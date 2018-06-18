/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache(());

/* Create an HTTP Link */
let httpLink =
    ApolloLinks.createHttpLink(~uri="https://api.graph.cool/simple/v1/civ0m09qx0uss0113an2cp5kj", ());

let instance = ReasonApollo.createApolloClient(
    ~link=httpLink, 
    ~cache=inMemoryCache, 
    ()
);