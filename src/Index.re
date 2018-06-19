ReactDOMRe.renderToElementWithId(
    <ReasonApollo.Provider client=Client.instance>
        <App />
    </ReasonApollo.Provider>,
"root");

ReasonReact.Router.push("");