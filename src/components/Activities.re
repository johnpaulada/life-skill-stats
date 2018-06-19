let component = ReasonReact.statelessComponent("Activities");

let make = (_children) => {
    ...component,
    render: _self =>
        <div>
            {ReasonReact.string("Awesome")}
        </div>,
};
