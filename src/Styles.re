let main = ReactDOMRe.Style.make(
  ~backgroundColor="#2E2C3D",
  ~width="100vw",
  ~minHeight="100vh",
  ~height="100%",
  ~display="grid",
  ~gridTemplateColumns="1fr 2fr 1fr",
  ~gridTemplateRows="10vh 6fr 1fr",
  ()
);

let body = ReactDOMRe.Style.make(
  ~gridRow="2 / 3",
  ~gridColumn="2 / 3",
  ~gridGap="40px",
  ~display="grid",
  ~gridTemplateColumns="minmax(500px, 5fr) minmax(140px, 1fr)",
  ~gridTemplateRows="100px 100px",
  ~gridAutoRows="200px",
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
  ~marginTop="60px",
  ~marginBottom="0",
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
  ~marginTop="60px",
  ~marginBottom="0",
  ()
);

let skillContainer = ReactDOMRe.Style.make(
  ~backgroundColor="#3A3949",
  ~gridColumn="1 / 3",
  ~borderRadius="20px",
  ~display="grid",
  ~gridTemplateColumns="3fr 1fr",
  ()
);

let skillTitle = ReactDOMRe.Style.make(
  ~color="#FAFAFA",
  ~fontFamily="Nunito Sans, sans-serif",
  ~fontWeight="900",
  ~fontSize="48px",
  ~letterSpacing="3px",
  ~margin="0",
  ~marginLeft="30px",
  ~marginTop="30px",
  ()
);

let skillPoints = ReactDOMRe.Style.make(
  ~fontFamily="Nunito Sans, sans-serif",
  ~fontWeight="100",
  ~fontSize="36px",
  ~color="#FAFAFA",
  ~textAlign="right",
  ~marginRight="30px",
  ~marginTop="43px",
  ~opacity="0.5",
  ()
);