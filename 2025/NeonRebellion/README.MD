# Neon Rebellion

<!-- crypto, forensics, osint, reversing, stegano, websec, misc -->
* Category: **Neon Rebellion**

<!-- * "uhctf{...}": must match regex "uhctf{([a-z0-9]+-)*[0-9a-f]{6}}" -->
<!-- * "free-form": anything goes, mention in description what to look for -->
* Flag Format: **UHCTF{...}**

<!-- Only enter people's first name in lowercase, it will be changed later -->
* Credits:
    * Robin


## Description and Solutions
This is a 6-part challenge, for which the first 5 (easy) parts give the equivalent amount of points as if they were 2 challenges. The final, main challenge, is unlocked by completing the 5 previous challenges.

The full description and solution per challenge can be found in Descriptions.md and Solutions.md

To try it again and run it without spoiling, check out this directory and do:

docker build -t neon-rebellion .

docker run -p 5000:5000 -p 8080:8080 neon-rebellion

url: http://localhost:8080/