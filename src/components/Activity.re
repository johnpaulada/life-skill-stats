let component = ReasonReact.statelessComponent("Activity");

let make = (~description, _children) => {
    ...component,
    render: _self =>
        <div style=Styles.activityContainer>
            <p style={Styles.activitiesDescription}>{ReasonReact.string(description)}</p>
        </div>,
};
