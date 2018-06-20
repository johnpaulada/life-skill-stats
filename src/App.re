type route =
    | Home
    | Skill(string)
    | AddSkill
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
        | ["skill", id] => Skill(id)
        | ["add_skill"] => AddSkill
        | _ => Home
};

let onSkillClick = id => (_event) => {
    ReasonReact.Router.push("skill/" ++ id);
};

let onAddSkill = (_event) => {
    ReasonReact.Router.push("add_skill");
};

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
    ...component,
    initialState: () => {route: Home},
    reducer,
    render: self => {
        switch self.state.route {
            | Home => <Home onAddSkill=onAddSkill onSkillClick=onSkillClick />
            | Skill(id) => <Activities id=id />
            | AddSkill => <AddSkill />
        };
    },
    subscriptions: (self) => [
        Sub(
            () => ReasonReact.Router.watchUrl(url => ChangeRoute(url |> mapUrlToRoute) |> self.send),
            ReasonReact.Router.unwatchUrl
        )
    ],
};
