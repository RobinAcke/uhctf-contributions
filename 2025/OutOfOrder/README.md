# Out of Order

<!-- crypto, forensics, osint, reversing, stegano, websec, misc -->
* Category: **Reverse Engineering**

<!-- * "uhctf{...}": must match regex "uhctf{([a-z0-9]+-)*[0-9a-f]{6}}" -->
<!-- * "free-form": anything goes, mention in description what to look for -->
* Flag Format: **UHCTF{...}**

<!-- {{FLAG_TYPE}} can be "static" or "regex" -->
* Flags: <details><summary>CLICK TO SHOW</summary><ul><ul>
<li>static: <code>UHCTF{So_long_and_thanks_for_all_the_fish-671a55}</code></li>
</ul></ul></details>

<!-- Only enter people's first name in lowercase, it will be changed later -->
* Credits:
    * Robin



## Description
<!-- HTML can be used here if needed -->
Help! I accidentally sorted all the lines of my Python script alphabetically, and now it doesn't work at all. It was supposed to print a flag, but now it's just a jumbled mess.

Don't panic - the code is all there, just in the wrong order.

## Solution

<details><summary>CLICK TO SHOW</summary><ul><ul>

Either manually fix the script, or write a brute-force script that tries all orders.
An example solution can be found in order_solution.py. The original code is found in original_code.py

</ul></ul></details>