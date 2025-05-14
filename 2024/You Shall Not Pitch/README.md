# You Shall Not Pitch

<!-- crypto, forensics, osint, reversing, stegano, websec, misc -->
* Category: **stegano**
  
<!-- * "uhctf{...}": must match regex "uhctf{([a-z0-9]+-)*[0-9a-f]{6}}" -->
<!-- * "free-form": anything goes, mention in description what to look for -->
* Flag Format: **UHCTF{}**

<!-- {{FLAG_TYPE}} can be "static" or "regex" -->
* Flag: <details><summary>CLICK TO SHOW</summary><ul><ul>
<li>static: <code>UHCTF{CAN_YOU_HEAR_ME?}</code></li>
</ul></ul></details>

<!-- Only enter people's first name in lowercase, it will be changed later -->
* Credits:
    * robin

## Description

You Shall Not Pitch!

Gandalf's famous words hide more than meets the ear. Uncover the flag and prove you're a wizard at steganography!

## Solution

<details><summary>CLICK TO SHOW</summary><ul><ul>
Run "steghide" on the file without passphrase
Then open the resulting .ogg file in Audacity

Play around with the spectogram and settings until you can see the flag; this requires the spectogram range to be set to a higher frequency as is hinted at in the metadata "There seems to be quite a lot of noises going on above 6k Hz".

Fun fact: I made this .ogg file using LMMS by drawing out the flag in the piano roll! You can see it in the added FLAG.mmpz project.

</ul></ul></details>

