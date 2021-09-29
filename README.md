> A block manager for lemonbar

![example](assets/example.png)

# Installation
```bash
$ git clone https://github.com/Murtaza-Udaipurwala/lemonaid
$ cd lemonaid
```

#### Edit `config.h` to your liking.

```bash
$ sudo make clean install
```

# Uninstall
```bash
$ sudo make clean uninstall
```

# Usage
- `Lemonaid` simply outputs lemonbar specific formatted text to stdout. You
  need to then pipe this output into `lemonbar`

- Eg: in your `xinitrc`
```bash
lemonaid | lemonbar -p -d -f "JetBrains Mono Nerd Font:style=medium:size=11" -B "#10151a" &
```

# Signaling changes
Most statusbars constantly rerun every script every several seconds to update.
This is an option here, but a superior choice is giving your module a signal
that you can signal to it to update on a relevant event, rather than having it
rerun idly.

For example, the volume module has the update signal 10 by default. Thus,
running pkill -RTMIN+10 lemonaid will update it.

My volume module never updates on its own, instead I have this command run
along side my volume shortcuts in `sxhkdrc` to only update it when relevant.

Note that all modules must have different signal numbers.

```bash
$ pkill -RTMIN+10 lemonaid
```
