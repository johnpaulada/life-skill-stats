module AddSkill = [%graphql {|
    mutation AddSkill($name: String!){
        createSkill(name: $name) {
        id
        name
        _activitiesMeta {
          count
        }
      }
    }
|}];

module AddSkillMutation = ReasonApollo.CreateMutation(AddSkill);

type state = {
    name: string
};

type action = 
    | ChangeName(string)
;

let reducer = (action, _state) =>
    switch action {
        | ChangeName(name) => ReasonReact.Update({name: name})
    };

let component = ReasonReact.reducerComponent("AddSkill");

let make = (_children) => {
    ...component,
    initialState: () => {name: ""},
    reducer,
    render: self => {
        <AddSkillMutation>
            ...((mutation, _result) => {
                let addSkill = AddSkill.make(~name=self.state.name, ());
                
                <div style=Styles.main>
                    <div style=Styles.addSkillContainer>
                        <h1 style={Styles.addSkillTitle}>{ReasonReact.string("Add Skill")}</h1>
                        <input _type="text" onChange=(
                            evt => {
                                let value = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(evt))##value;
                                self.send(ChangeName(value))
                            }
                        ) />
                        <button onClick=((_mouseEvent) => {
                            mutation(
                                ~variables=addSkill##variables,
                                ~refetchQueries=[|"AllSkills"|],
                            ()) |> ignore;
                            ReasonReact.Router.push("/");
                        })>{ReasonReact.string("Add")}</button>
                    </div>
                </div>
            })
        </AddSkillMutation>
    }
};
