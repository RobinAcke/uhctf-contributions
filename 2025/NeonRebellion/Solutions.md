## The eye of the beholder
Run the command “strings” on favicon.ico.

UHCTF{3f12300e2ff92fef40d8e0754ecce7c9}

## The Letters of Law
Open font.ttf in FontForge (which is hinted at in meta-data).

UHCTF{fontastic-find-hd3nb8}

## The Robots of the Apocalypse
Open the .git/ directory, check it out and open the dump in git. One of the commits contains a plain text flag.

A hint for this challenge could be found in “robots.txt”, which lists the .git directory.

UHCTF{488ac8bf99c626d90da03889f87f8a0b}

## The Background of the Rebellion
Open background.png, use OCR to convert the image to text. Convert this text from hex to string, which is a base 64 string that decodes to a piece of text that includes the flag.  

UHCTF{do-not-steal-my-manifesto-5d3a9c}

## The Style of the Manifesto
Open the .css file, and switch the regular letters to invisible and the hidden letters to visible on the page manifesto.html  

UHCTF{b02bb8a220a13e1c3}

## The Ultimate Hacktivist

Log in, after which the frontend goes to flag.html  
This page does 4 requests:

* /whoami
* /user/{uuid}  
* /user/role/{uuid}  
* /flag

The login gives a token (JWT) which is needed for all requests. It is used with /whoami to get UUID of the logged in user.

The endpoint /user/{uuid} also works with a normal id so by testing random ids, the id 3 gives back the info for an admin account, including the admin’s uuid.

The endpoint /user/role/uuid called with this uuid gives the required role for the admin account.

You need to make your own valid token with this role. To sign this token, you can find the signing key in the git history from the prior challenge in which the .git directory was found. The structure can be copied from your original token.

To obtain the flag, send a request to /flag with this new token.  

UHCTF{MK\_Ultra\_3xP0s3\_Th3\_TrUth\!-9cf4ca70}