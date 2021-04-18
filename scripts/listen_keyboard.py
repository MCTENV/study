#!/usr/bin/env python
# coding=utf-8
from pynput import keyboard

def on_press(key):
    '按下按键时执行。'
    try:
        if key == keyboard.KeyCode.from_char('q'):
            print('quit')
        else:
            print('not quit')
    except AttributeError:
        print('special key {0} pressed'.format(
            key))
    #通过属性判断按键类型。

def on_release(key):
    '松开按键时执行。'
    print('{0} released'.format(
        key))
    if key == keyboard.Key.esc:
        # Stop listener
        return False

# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
