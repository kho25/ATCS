# NO IMPORTS ALLOWED!

def make_2d_array(num_rows, num_cols, val):
    result = []
    for r in range(num_rows):
        row = []
        for c in range(num_cols):
            row.append(val)
        result.append(row)
    return result

def is_in_bounds(r, c, dims):
    return r >= 0 and c >= 0 and r < dims[0] and c < dims[1]


def get_neighbors(bomb, dims):
    neighbors = []
    row = bomb[0]
    col = bomb[1]

    for r in range(row-1, row+2):
        for c in range(col-1, col+2):
            if is_in_bounds(r, c, dims):
                neighbors.append((r,c))

    return neighbors

    

def new_game(num_rows, num_cols, bombs):
    """Start a new game. Should return a dictionary with the following keys:
       * `dimensions`
       * `state`
       * `board`
       * `visible`

    Each of these should be as described in the handout.
    Parameters:
       num_rows (int): Number of rows
       num_cols (int): Number of columns
       bombs (set/tuple): Set of bombs, given in (row, column) pairs (tuples)
    """
    
    visible_board = make_2d_array(num_rows, num_cols, False)
    num_board = make_2d_array(num_rows, num_cols, 0)

    for bomb in bombs:
        num_board[bomb[0]][bomb[1]] = '.'
        for r, c in get_neighbors(bomb, (num_rows, num_cols)):
            if num_board[r][c] != '.':
                num_board[r][c] += 1

    return {'dimensions' : (num_rows, num_cols),
            'state' : 'ongoing',
            'board' : num_board,
            'visible' : visible_board}

def dig(game, row, col):
    """
    Recursively dig up (row, col) and neighboring squares.
    Update game["visible"] to reveal (row, col); then recursively reveal (dig up)
    its neighbors, as long as (row, col) does not contain and is not adjacent
    to a bomb.  Return an integer indicating how many new squares were
    revealed.
    Parameters:
       game (dict): game represented as a dictionary, same format as new_game
       row (int): Where to start digging (row)
       col (int): Where to start digging (col)
    Returns:
       int: the number of new squares revealed
    """

    if game['visible'][row][col]:
        return 0
    elif game['board'][row][col] != 0:
        game['visible'][row][col] = True
        return 1
    else: #it's 0
        counter = 0
        game['visible'][row][col] = True
        for r, c in get_neighbors((row, col), game['dimensions']):
            counter += dig(game, r, c)
        return counter
    
def check_game_over(game):
    """
    Two things need to happen: game["state"] should change and the function
    should return if the game is over or not.

    The state of the game should be changed to "defeat" if at least one bomb
    is visible on the board, "victory" when all safe squares (squares that 
    do not contain a bomb) and no bombs are visible, and "ongoing" otherwise.

    Function should return True if the game is over (i.e. victory or defeat has happened), 
    and False otherwise (i.e. if the game is still ongoing)
    """
    result = True

    for r in range(len(game['board'])):
        for c in range(len(game['board'][0])):
            if game['board'][r][c] == '.' and game['visible'][r][c]:
                game['state'] = 'defeat'
                return True
            elif not game['visible'][r][c] and game['board'][r][c] != '.':
                result = False
    if result:
        game['state'] = 'victory'
        return True
    else:
        game['state'] = 'ongoing'
        return False

def dump(game):
    """
    Print a human-readable representation of this game. You can use this to check your code
    if it's helpful!
    """

    lines = ["dimensions: {}".format(game['dimensions']),
             "board: {}".format("\n       ".join(map(str, game["board"]))),
             "visible:  {}".format("\n       ".join(map(str, game["visible"]))),
             "state: {}".format(game['state']),
             ]
    print("\n".join(lines))

if __name__ == "__main__":
    # feel free to use the main method to test your methods!
    pass