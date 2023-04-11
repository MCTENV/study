from ubuntu:18.04 as base-os
run apt update &&\
    apt install vim &&\
    apt clean && rm -rf /var/lib/apt/lists

from base-os
run apt update &&