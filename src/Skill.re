/* This is the basic component. */
let component = ReasonReact.statelessComponent("Skill");

let make = (~name: string, ~points: int, _children) => {
    ...component,
    render: _self =>
        <div style=(Styles.skillContainer)>
            <h3 style=(Styles.skillTitle)>
                {ReasonReact.string(name)}
            </h3>
            <span style=(Styles.skillPoints)>
                {ReasonReact.string(string_of_int(points) ++ " pts.")}
            </span>
            <div style=(Styles.skillProgressContainer)>
                <progress value="2" max="5" style=(Styles.skillProgress)></progress>
            </div>
            <div style=(Styles.skillActionsContainer)>
                <button style=(Styles.addSkillButton)>{ReasonReact.string("Add")}</button>
                <span style=(Styles.skillLevel)>
                    {ReasonReact.string("lvl " ++ string_of_int(10))}
                </span>
            </div>
        </div>,
};
