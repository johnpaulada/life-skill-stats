/* This is the basic component. */
let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self =>
    <div>
      <Hero />
    </div>,
};
