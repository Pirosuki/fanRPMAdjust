## _**MODIFYING HARDWARE CAN BE DANGEROUS! USE THIS SCRIPT AT YOUR OWN RISK.**_

# fanRPMAdjust
This is a script I wrote to trick my UPS into thinking that the noctua fans I put into it are the factory installed ones.

### What does it do?
It reads the rpm value that your new fan outputs and modifies it to match what the old one would send out. Simply modify the variable _rpmDivider_ to match the rpm difference between your fans. I recommend comparing fan spec sheets and seeing if you can figure it out that way.
