let component = ReasonReact.statelessComponent("Home");

module AllSkills = [%graphql {|
    query AllSkills {
        allSkills {
            id
            name
            _activitiesMeta {
                count
            }
        }
      }
|}]; 
  
module AllSkillsQuery = ReasonApollo.CreateQuery(AllSkills);

let make = (~onAddSkill, ~onSkillClick, _children) => {
    ...component,
    render: _self => {
        <AllSkillsQuery>
            ...(({result}) => {
                <div style=(Styles.main)>
                    <div style=(Styles.body)>
                        <h1 style=(Styles.name)>{ReasonReact.string("John Paul Ada")}</h1>
                        <h2 style=(Styles.skillsLabel)>{ReasonReact.string("SKILLS")}</h2>
                        <button style=(Styles.addSkill) onClick={onAddSkill}>{ReasonReact.string("Add Skill")}</button>
                        {switch result {
                            | Loading => <div> (ReasonReact.string("Loading")) </div>
                            | Error(error) => <div> (ReasonReact.string(error##message)) </div>
                            | Data(response) => {
                                {response##allSkills
                                    |> Array.map(skill => <Skill key={skill##id} onSkillClick=onSkillClick(skill##id) name={skill##name} points={skill##_activitiesMeta##count} />)
                                    |> ReasonReact.array}
                            }  
                        }}
                    </div>
                </div>
            })
        </AllSkillsQuery>
    },  
};
