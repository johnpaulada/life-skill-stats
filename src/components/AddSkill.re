let component = ReasonReact.statelessComponent("AddSkill");

let make = (_children) => {
    ...component,
    render: _self =>
        <div>
            {ReasonReact.string("Add Skill")}
        </div>,
};
