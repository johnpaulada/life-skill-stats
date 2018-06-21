module AddActivity = [%graphql {|
    mutation AddActivity($skillId: ID!, $description: String!) {
        createActivity(description: $description, skillId: $skillId) {
            id
        }
    }
|}];

module AddActivityMutation = ReasonApollo.CreateMutation(AddActivity);

type state = {
    description: string
};

type action = 
    | ChangeDescription(string)
;

let reducer = (action, _state) =>
    switch action {
        | ChangeDescription(description) => ReasonReact.Update({description: description})
    };

let component = ReasonReact.reducerComponent("ActivityForm");

let make = (~skillId, _children) => {
    ...component,
    initialState: () => {description: ""},
    reducer,
    render: self => {
        <AddActivityMutation>
            ...((mutation, _result) => {

                let addActivity = AddActivity.make(~skillId, ~description=self.state.description, ());

                <div style=(Styles.addActivityFormContainer)>
                    <input
                        style=(Styles.addSkillFormInput)
                        _type="text" placeholder="Activity Description, e.g. Sleepwalked barefoot at 3 AM..."
                        onChange=(
                            evt => {
                                let value = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(evt))##value;
                                self.send(ChangeDescription(value))
                            }
                        )
                    />
                    <button
                        style=(Styles.addSkillFormButton)
                        onClick=((_mouseEvent) => {
                            mutation(
                                ~variables=addActivity##variables,
                                ~refetchQueries=[|"ActivitiesOnSkill"|],
                            ()) |> ignore;
                        })
                    >{ReasonReact.string("Add")}</button>
                </div>
            })
        </AddActivityMutation>
    }
};
