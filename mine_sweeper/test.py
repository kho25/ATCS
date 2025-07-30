#!/usr/bin/env python3
import mines
import unittest

class Test00_NewGame(unittest.TestCase):
    def test_new_smolgame(self):
        result = mines.new_game(4, 3, [(0, 1), (1, 2), (3, 0)])
        expected = {
                    'dimensions': (4, 3),
                    'board': [[1,  '.',  2], [1,   2,  '.'], [1,   2,   1], ['.', 1,   0]],
                    'visible': [[False, False, False], [False, False, False], [False, False, False], [False, False, False]],
                    'state': 'ongoing',
                    }
        for name in expected:
            self.assertEqual(result[name], expected[name])

    def test_new_medgame(self):
        result = mines.new_game(10, 8, [(7, 3), (2, 6), (8, 7), (4, 4), (3, 5),
                                         (4, 6), (6, 2), (9, 4), (4, 2), (4, 0),
                                         (8, 6), (9, 7), (8, 5), (5, 0), (7, 2),
                                         (5, 3)])
        expected = {"board": [[0, 0, 0, 0, 0, 0, 0, 0],
                              [0, 0, 0, 0, 0, 1, 1, 1],
                              [0, 0, 0, 0, 1, 2, ".", 1],
                              [1, 2, 1, 2, 2, ".", 3, 2],
                              [".", 3, ".", 3, ".", 3, ".", 1],
                              [".", 4, 3, ".", 2, 2, 1, 1],
                              [1, 3, ".", 4, 2, 0, 0, 0],
                              [0, 2, ".", ".", 2, 2, 3, 2],
                              [0, 1, 2, 3, 3, ".", ".", "."],
                              [0, 0, 0, 1, ".", 3, 4, "."]],
                    "dimensions": (10, 8),
                    "visible": [[False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False],
                             [False, False, False, False, False, False, False, False]],
                    "state": "ongoing"}
        for name in expected:
            self.assertEqual(result[name], expected[name])


class Test01_Dig(unittest.TestCase):
    def test_dig_seen(self):
        game = {
                'dimensions': (5, 5),
                'board': [[1, 2, '.', 1, 0], [1, '.',  2, 1, 0], [1, 1, 1, 1, 1], [1, 1, 0, 1, '.'], ['.', 1, 0, 1, 1]],
                'visible': [[True, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_game = {
                'dimensions': (5, 5),
                'board': [[1, 2, '.', 1, 0], [1, '.',  2, 1, 0], [1, 1, 1, 1, 1], [1, 1, 0, 1, '.'], ['.', 1, 0, 1, 1]],
                'visible': [[True, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_num = 0
        num_dug = mines.dig(game,0,0)
        for name in expected_game:
            self.assertEqual(game[name], expected_game[name])
        self.assertEqual(num_dug, expected_num)

    def test_dig_num(self):
        game = {
                'dimensions': (5, 5),
                'board': [[1,   2,  '.', 1, 0], 
                          [1,  '.',  2,  1, 0], 
                          [1,   1,   1,  1, 1], 
                          [1,   1,   0,  1, '.'], 
                          ['.', 1,   0,  1, 1]],
                'visible': [[False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_game = {
                'dimensions': (5, 5),
                'board': [[1, 2, '.', 1, 0], [1, '.',  2, 1, 0], [1, 1, 1, 1, 1], [1, 1, 0, 1, '.'], ['.', 1, 0, 1, 1]],
                'visible': [[True, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_num = 1
        num_dug = mines.dig(game,0,0)
        for name in expected_game:
            self.assertEqual(game[name], expected_game[name])
        self.assertEqual(num_dug, expected_num)

    def test_dig_recurse(self):
        game = {
                'dimensions': (5, 5),
                'board': [[1,   2,  '.', 1, 0], 
                          [1,  '.',  2,  1, 0], 
                          [1,   1,   1,  1, 1], 
                          [1,   1,   0,  1, '.'], 
                          ['.', 1,   0,  1, 1]],
                'visible': [[False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_game = {
                'dimensions': (5, 5),
                'board': [[1, 2, '.', 1, 0], [1, '.',  2, 1, 0], [1, 1, 1, 1, 1], [1, 1, 0, 1, '.'], ['.', 1, 0, 1, 1]],
                'visible': [[False, False, False, True, True], [False, False, False, True, True], [False, False, False, True, True], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_num = 6
        num_dug = mines.dig(game, 0,4)
        for name in expected_game:
            self.assertEqual(game[name], expected_game[name])
        self.assertEqual(num_dug, expected_num)

    def test_dig_bomb(self):
        game = {
                'dimensions': (5, 5),
                'board': [[1, 2, '.', 1, 0], [1, '.',  2, 1, 0], [1, 1, 1, 1, 1], [1, 1, 0, 1, '.'], ['.', 1, 0, 1, 1]],
                'visible': [[False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_game = {
                'dimensions': (5, 5),
                'board': [[1, 2, '.', 1, 0], [1, '.',  2, 1, 0], [1, 1, 1, 1, 1], [1, 1, 0, 1, '.'], ['.', 1, 0, 1, 1]],
                'visible': [[False, False, True, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False], [False, False, False, False, False]],
                'state': 'ongoing',
                }
        expected_num = 1
        num_dug = mines.dig(game, 0,2)
        for name in expected_game:
            self.assertEqual(game[name], expected_game[name])
        self.assertEqual(num_dug, expected_num)


class Test02_CheckVictory(unittest.TestCase):
    def test_ongoing(self):
        game = {
                'dimensions': (4, 3),
                'board': [[1,  '.',  2], [1,   2,  '.'], [1,   2,   1], ['.', 1,   0]],
                'visible': [[False, False, False], [False, False, False], [False, False, False], [False, False, False]],
                'state': 'ongoing',
                }
        expected_game = {
                'dimensions': (4, 3),
                'board': [[1,  '.',  2], [1,   2,  '.'], [1,   2,   1], ['.', 1,   0]],
                'visible': [[False, False, False], [False, False, False], [False, False, False], [False, False, False]],
                'state': 'ongoing',
                }
        state = mines.check_game_over(game)
        self.assertFalse(state, msg="check_game_over returned incorrect value.")
        for name in expected_game:
            self.assertEqual(game[name], expected_game[name])

    def test_defeat(self):
        game = {
                'dimensions': (4, 3),
                'board': [[1,  '.',  2], [1,   2,  '.'], [1,   2,   1], ['.', 1,   0]],
                'visible': [[False, True, False], [False, False, False], [False, False, False], [False, False, False]],
                'state': 'ongoing',
                }
        expected_game = {
                'dimensions': (4, 3),
                'board': [[1,  '.',  2], [1,   2,  '.'], [1,   2,   1], ['.', 1,   0]],
                'visible': [[False, True, False], [False, False, False], [False, False, False], [False, False, False]],
                'state': 'defeat',
                }
        state = mines.check_game_over(game)
        self.assertTrue(state, msg="check_game_over returned incorrect value.")
        for name in expected_game:
            self.assertEqual(game[name], expected_game[name])

    def test_victory(self):
        game = {
                'dimensions': (4, 3),
                'board': [[1,  '.',  2], [1,   2,  '.'], [1,   2,   1], ['.', 1,   0]],
                'visible': [[True, False, True], [True, True, False], [True, True, True], [False, True, True]],
                'state': 'ongoing',
                }
        expected_game = {
                'dimensions': (4, 3),
                'board': [[1,  '.',  2], [1,   2,  '.'], [1,   2,   1], ['.', 1,   0]],
                'visible': [[True, False, True], [True, True, False], [True, True, True], [False, True, True]],
                'state': 'victory',
                }
        state = mines.check_game_over(game)
        self.assertTrue(state, msg="check_game_over returned incorrect value.")
        for name in expected_game:
            self.assertEqual(game[name], expected_game[name])



class Test03_Integration(unittest.TestCase):
    def test_all(self):
        game = mines.new_game(3, 4, [(2, 1), (1, 0)])

        expected_new = {
                        'dimensions': (3, 4), 
                        'state': 'ongoing', 
                        'board': [[1, 1, 0, 0], ['.', 2, 1, 0], [2, '.', 1, 0]], 
                        'visible': [[False, False, False, False], [False, False, False, False], [False, False, False, False]]
                        }

        for name in expected_new:
            self.assertEqual(game[name], expected_new[name], msg="New game "+name+" not correct.")

        d1 = mines.dig(game, 0, 0)
        self.assertEqual(d1, 1, msg="First dig wrong number.")

        d2 = mines.dig(game, 1, 3)
        self.assertEqual(d2, 8, msg="Second dig wrong number.")
        
        state1 = mines.check_game_over(game)
        self.assertFalse(state1, msg="check_game_over returned incorrect value after 2 digs.")

        s1_expected_game = {
                            'dimensions': (3, 4), 
                            'state': 'ongoing', 
                            'board': [[1, 1, 0, 0], ['.', 2, 1, 0], [2, '.', 1, 0]],
                            'visible': [[True, True, True, True], [False, True, True, True], [False, False, True, True]]
                            }

        for name in s1_expected_game:
            self.assertEqual(game[name], s1_expected_game[name], msg="Game "+name+" not correct after 2 digs.")
        
        d3 = mines.dig(game, 2, 0)
        state2 = mines.check_game_over(game)

        s2_expected_game = {
                            'dimensions': (3, 4), 
                            'state': 'victory', 
                            'board': [[1, 1, 0, 0], ['.', 2, 1, 0], [2, '.', 1, 0]], 
                            'visible': [[True, True, True, True], [False, True, True, True], [True, False, True, True]]
                            }

        self.assertEqual(d2, 8, msg="Third dig wrong number.")
        self.assertTrue(state2, msg="check_game_over returned incorrect value after 3 digs.")
        for name in s2_expected_game:
            self.assertEqual(game[name], s2_expected_game[name], msg="Game "+name+" not correct after 3 digs.")


if __name__ == '__main__':
    res = unittest.main(verbosity=3, exit=False)