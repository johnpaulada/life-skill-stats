/* This is the basic component. */
let component = ReasonReact.statelessComponent("Body");

let make = (_children) => {
  ...component,
  render: _self =>
    <div>
    </div>,
};
