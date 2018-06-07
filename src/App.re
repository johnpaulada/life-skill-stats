/* This is the basic component. */
let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self =>
    <div style=(Styles.main)>
      <div style=(Styles.body)>
        <h1 style=(Styles.name)>{ReasonReact.string("John Paul Ada")}</h1>
        <h2 style=(Styles.skillsLabel)>{ReasonReact.string("SKILLS")}</h2>
        <button style=(Styles.addSkill)>{ReasonReact.string("Add Skill")}</button>
      </div>
    </div>,
};
