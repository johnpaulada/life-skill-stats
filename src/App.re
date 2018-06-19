type route =
    | Home
    | Skill
;

type state = {
    route: route
};

type action =
    | ChangeRoute(route)
;

let reducer = (action, _state) =>
    switch action {
        | ChangeRoute(route) => ReasonReact.Update({route: route})
};

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
    switch url.path {
        | [] => Home
        | ["skill"] => Skill
        | _ => Home
};

let onSkillClick = (_event) => {
    ReasonReact.Router.push("skill");
};

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
    ...component,
    initialState: () => {route: Home},
    reducer,
    render: self => {
        switch self.state.route {
            | Home => <Home onAddSkill=onSkillClick />
            | Skill => <Activities />
        };
    },
    subscriptions: (self) => [
        Sub(
            () => ReasonReact.Router.watchUrl((url) => self.send(ChangeRoute(url |> mapUrlToRoute))),
            ReasonReact.Router.unwatchUrl
        )
    ],
};
