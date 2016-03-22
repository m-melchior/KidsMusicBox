/* KidsMusicBox - Music Box for kids
 * Copyright (C) 2016 Michael Melchior <MelchiorMichael@web.de>
 *
 * This program is free software: You can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
 *                         kidsMusicBox.ino  -  description
 *                         ------------------------------------------
 *   begin                : written in 2016 by Michael Melchior
 *   copyright            : (c) 2016 by Michael Melchior
 *   description          : An application to play music on an Arduino Uno with a MP3 music shield
 *
*/

/* 
 * This little program is using the Seeed Studio Music Shield library
 * written by Jack Shao (jacky.shaoxg@gmail.com) for seeed studio
 * and which is licensed under The MIT License.
 * It can be found in their github repository under https://github.com/Seeed-Studio/Music_Shield.
 * Check their License.txt for more information.
*/

#include <arduino.h>
#include <MusicPlayer.h>
#include <SD.h>
#include <SPI.h>

int volumePin = A5;
int volumeInput = 0;
unsigned char myVolume = 0;
unsigned char oldVolume = 0;

void setup() {
  player.begin();
  player.setPlayMode(PM_REPEAT_LIST);
  player.scanAndPlayAll();
} // void setup()

void loop() {
  player.play();
  
  myVolume = map(analogRead(volumePin), 0 , 1023, 20, 70);
  
  if (abs(oldVolume - myVolume) > 2) {
    player.setVolume(myVolume);
    oldVolume = myVolume;
  } // if (abs(oldVolume - myVolume) > 2) {
} // void loop() {
