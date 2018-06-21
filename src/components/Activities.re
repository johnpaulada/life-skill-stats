let component = ReasonReact.statelessComponent("Activities");

module ActivitiesOnSkill = [%graphql {|
    query ActivitiesOnSkill($id: ID!) {
        allActivities(filter: {skill: {id: $id}}) {
            id
            description
            skill {
                name
            }
        }
    }
|}]; 

module ActivitiesQuery = ReasonApollo.CreateQuery(ActivitiesOnSkill);

let getSkillName = response => {
    let activities = response##allActivities |> ArrayLabels.to_list;

    switch activities {
        | [first, ..._] => switch first##skill {
                | Some(skill) => skill##name
                | None => ""
            };
        | [] => ""
    }
}

let make = (~id, _children) => {
    ...component,
    render: _self => {
        let activitiesQuery = ActivitiesOnSkill.make(~id, ());

        <ActivitiesQuery variables=activitiesQuery##variables>
            ...(({result}) => {
                <div style=Styles.main>
                    {switch result {
                        | Loading => <div> (ReasonReact.string("Loading")) </div>
                        | Error(error) => <div> (ReasonReact.string(error##message)) </div>
                        | Data(response) => {
                            <div style=Styles.activitiesContainer>
                                <h1 style={Styles.activitiesTitle}>(ReasonReact.string(getSkillName(response)))</h1>
                                <div style=(Styles.addActivityFormContainer)>
                                    <input style=(Styles.addSkillFormInput) _type="text" placeholder="Activity Description, e.g. Sleepwalked barefoot at 3 AM..." />
                                    <button style=(Styles.addSkillFormButton)>{ReasonReact.string("Add")}</button>
                                </div>
                                {response##allActivities
                                    |> Array.map(activity => <Activity key=activity##id description=activity##description />)
                                    |> ReasonReact.array}
                            </div>
                        }
                    }}
                </div>
            })
        </ActivitiesQuery>
    }
};
