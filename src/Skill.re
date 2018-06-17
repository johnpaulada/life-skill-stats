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
        </div>,
};
