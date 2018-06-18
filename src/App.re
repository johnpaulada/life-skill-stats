/* This is the basic component. */
let component = ReasonReact.statelessComponent("App");

module AllSkills = [%graphql {|
    query AllSkills {
        allSkills {
          name
          _activitiesMeta {
            count
          }
        }
      }
|}]; 
  
 module AllSkillsQuery = ReasonApollo.CreateQuery(AllSkills);
  

let make = (_children) => {
    ...component,
    render: _self => {
        <AllSkillsQuery>
            ...(({result}) => {
                switch result {
                    | Loading => <div> (ReasonReact.string("Loading")) </div>
                    | Error(error) => <div> (ReasonReact.string(error##message)) </div>
                    | Data(response) => {
                        
                        <div style=(Styles.main)>
                            <div style=(Styles.body)>
                                <h1 style=(Styles.name)>{ReasonReact.string("John Paul Ada")}</h1>
                                <h2 style=(Styles.skillsLabel)>{ReasonReact.string("SKILLS")}</h2>
                                <button style=(Styles.addSkill)>{ReasonReact.string("Add Skill")}</button>
                                {response##allSkills
                                    |> Array.map(skill => <Skill name={skill##name} points={skill##_activitiesMeta##count} />)
                                    |> ReasonReact.array}
                            </div>
                        </div>
                    }  
                }
            })
            
        </AllSkillsQuery>

    },  
};
