let component = ReasonReact.statelessComponent("Activities");

module ActivitiesOnSkill = [%graphql {|
    query ActivitiesOnSkill($id: ID!) {
        allActivities(filter: {skill: {id: $id}}) {
            description
        }
    }
|}]; 

module ActivitiesQuery = ReasonApollo.CreateQuery(ActivitiesOnSkill);

let make = (~id, _children) => {
    ...component,
    render: _self => {
        let activitiesQuery = ActivitiesOnSkill.make(~id, ());

        <ActivitiesQuery variables=activitiesQuery##variables>
            ...(({result}) => {
                <div>
                    {switch result {
                        | Loading => <div> (ReasonReact.string("Loading")) </div>
                        | Error(error) => <div> (ReasonReact.string(error##message)) </div>
                        | Data(response) => {
                            {response##allActivities
                                |> Array.map(activity => <span>{ReasonReact.string(activity##description)}</span>)
                                |> ReasonReact.array}
                        }  
                    }}
                </div>
            })
        </ActivitiesQuery>
    }
};
