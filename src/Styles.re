let main = ReactDOMRe.Style.make(
  ~backgroundColor="#2E2C3D",
  ~width="100vw",
  ~height="100vh",
  ~display="grid",
  ~gridTemplateColumns="1fr 3fr 1fr",
  ~gridTemplateRows="1fr 6fr 1fr",
  ()
);

let body = ReactDOMRe.Style.make(
  ~gridRow="2 / 3",
  ~gridColumn="2 / 3",
  ~gridGap="40px",
  ~display="grid",
  ~gridTemplateColumns="5fr 1fr",
  ~gridTemplateRows="100px 100px",
  ()
);

let name = ReactDOMRe.Style.make(
  ~gridColumn="1 / 3",
  ~fontFamily="Titan One, sans-serif",
  ~fontSize="72px",
  ~color="#FAFAFA",
  ~letterSpacing="3px",
  ()
);

let skillsLabel = ReactDOMRe.Style.make(
  ~fontFamily="Nunito Sans, sans-serif",
  ~fontWeight="100",
  ~fontSize="36px",
  ~color="#E27F85",
  ~letterSpacing="5px",
  ()
);

let addSkill = ReactDOMRe.Style.make(
  ~fontFamily="Nunito Sans, sans-serif",
  ~fontWeight="100",
  ~fontSize="20px",
  ~color="#FAFAFA",
  ~backgroundColor="#E27F85",
  ~maxHeight="50px",
  ~padding="10px",
  ~margin="30px 0",
  ~border="none",
  ~borderRadius="20px",
  ()
);