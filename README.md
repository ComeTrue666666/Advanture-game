# Advanture-game

In this program, the player will fight against several enemies on 4
different floors (floor number is modifiable) and earn currency and scores by defeating enemies.
Once the enemy on floor 4 is defeated, the game is over and the
player information will be saved to certain files.
When the program is executed, it will ask if the player has an
existing file. If there is no existing file, the program will ask the player
to enter a name and create a file for the player automatically. If there
is an existing file, then the program will find the file and import the
player information from the player file into the game and use that as
the player's basic information (max health, currency, score, etc).
Then, a main menu page will come out. In this page, the user
can choose to watch the scoreboard list in different orders and
sequences. The scoreboard list is the information about other players’
game information, which was stored in the scoreboard.txt file together.
The scoreboard list reads this information from the scoreboard.txt file.
The user can choose to quit the game by entering ‘q’.
After that, the program will ask for the difficulty mode. The
enemy’s basic elements will be adjusted according to the difficulty
mode that is chosen by the player.
After that, the game officially starts, the player will be asked what
action they would like to take. There are 5 options available: Examine
self, Continue (fight enemy), Buy from the shop (purchase weapons),
Scoreboard (check current score), and Return (Return to the main
Menu page). Each time the player reaches a new floor, there will be
some new weapon available on the shop. Besides, there will be a side
quest when the player reaches a new floor. Completing these quests
will add extra scores to the player’s scoreboard.
When the player chooses to Continue, an enemy will appear and
attack the player first. The player again has 3 choices: Attack enemy,
check enemy information, examine the self and change weapon.
When the player chooses to attack an enemy, he will attack the enemy
and cause damage based on the attack damage. When the enemy is
defeated, the enemy will be stored on the defeated-enemy stack. This
stack will be printed out when the player chooses to quit the game and
end the program. Also, the player will receive a bounty that can be
used to purchase weapons and move to the next floor. Everytime an
enemy is defeated, a combat log that shows the player and enemy’s
HP changes during the combat will pop up. When the player chooses
to change weapons, a weapon list will come out if it is not empty. The
player can use the weapon on the list by typing the name of the
weapon, but these weapons can only be used once. After being used,
the weapon will be used up, it will disappear from the weapon list and
the player’s weapon will be switched to fist automatically.
When the enemy is defeated, again, the player will be given the
same 5 options: Examine self, Continue (fight enemy), Buy from the
shop (purchase weapons), Scoreboard (check current score), and
Return (Return to the main Menu page). However, The enemy on the
next floor will be stronger than the previous. The game will end until
the player is killed by the enemy or the player passes the 4th floor.
When the game ends, the sorted scoreboard will be printed out
based on the scores of the players. Then, the program will print out
the side quests that the player has done, if the player has ever
finished any side quest during the game. The enemies that were
defeated during the game will also be printed out at this point
