[@bs.val] external url : string = "process.env.GRAPHQL_URL";

/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache(());

/* Create an HTTP Link */
let httpLink =
    ApolloLinks.createHttpLink(~uri=url, ());

let instance = ReasonApollo.createApolloClient(
    ~link=httpLink, 
    ~cache=inMemoryCache, 
    ()
);