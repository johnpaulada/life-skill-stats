/* This is the basic component. */
let component = ReasonReact.statelessComponent("Hero");

let make = (_children) => {
  ...component,
  render: _self =>
    <div>
      <section className="hero is-dark is-bold">
        <div className="hero-body">
          <div className="container">
            <h1 className="title">
              (ReasonReact.string("Life Skill Stats"))
            </h1>
            <h2 className="subtitle">
              (ReasonReact.string("Need to level up."))
            </h2>
          </div>
        </div>
      </section>
    </div>,
};
