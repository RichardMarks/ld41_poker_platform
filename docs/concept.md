local multiplayer platformer poker game
jump around the level collecting cards

once you have collected 5 cards, you
are unable to collect more cards.

once all players have collected 5 cards,

the player with the winning poker hand will win a point
and will be able to collect new cards

first player to reach five wins is the game winner and the
game ends back to the title scene


scenes:

title scene
  play
  options
    sound toggle
    music toggle
    configure input
      use controllers | use keyboard
      if use controllers:
        configure player 1
        configure player 2
      if use keyboard:
        configure player 1
        configure player 2
  credits
  quit

player join scene
  if use controllers:
    press button on controller to join
  if use keyboard:
    press the configured "jump" key for each player

platformer scene
  in game pause menu for either player
    resume
    exit to title

game start -> title scene -> player join scene -> platformer scene -> title scene


poker hands in order of rank

royal flush: A K Q J 10 all same suit
straight flush: five cards in sequence all same suit 8♣️ 7♣️ 6♣️ 5♣️ 4♣️
four of a kind: any four same ranked cards eg A A A A 3
full house: three of a kind with a pair eg 8 8 8 3 3
flush: five cards of the same suit not in sequence
straight: five cards in a sequence not of the same suit
three of a kind: three cards of the same rank eg 8 8 8 K J
two pair: two different pairs eg 4 4 7 7 K
pair: any two same ranked cards eg Q Q 1 4 7
high card: highest ranked card is dominant if none of the above hands are met eg jack is high in 3 5 J 2 4

cards in order of rank
A K Q J 10 9 8 7 6 5 4 3 2
