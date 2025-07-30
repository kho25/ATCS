import json

def make_actor_dictionary(data):
    actor_dict = {}
    for actor_pair in data:
        actor0, actor1, movie = actor_pair
        if actor0 in actor_dict:
            actor_dict[actor0].add(actor1)
        else:
            actor_dict[actor0] = {actor1}

        if actor1 in actor_dict:
            actor_dict[actor1].add(actor0)
        else:
            actor_dict[actor1] = {actor0}  
    return actor_dict

def did_x_and_y_act_together(data, actor_id_1, actor_id_2):
    actor_dict = make_actor_dictionary(data)
    return actor_id_2 in actor_dict[actor_id_1] or actor_id_2 in actor_dict[actor_id_1]

def get_actors_with_bacon_number(data, n):
    actor_dict = make_actor_dictionary(data)
    queue = [(4724, 0)]
    visited = set()
    actors = set()

    while len(queue):
        actor, bacon_num = queue.pop(0)
        if bacon_num == n and actor not in visited:
            actors.add(actor)
        elif actor not in visited:
            visited.add(actor)
            connected_actors = actor_dict[actor]
            for other_actor in connected_actors:
                if other_actor not in visited:
                    queue.append((other_actor, bacon_num+1))
    return actors

def get_bacon_path(data, actor_id):
    actor_dict = make_actor_dictionary(data)
    queue = [[4724]]
    visited = set()

    while len(queue):
        actor_path = queue.pop(0)
        actor = actor_path[-1]
        if actor_id == actor:
            return actor_path
        elif actor not in visited:
            visited.add(actor)
            connected_actors = actor_dict[actor]
            for other_actor in connected_actors:
                if other_actor not in visited:
                    new_path = actor_path + [other_actor]
                    queue.append(new_path)
    return None

def get_path(data, actor_id_1, actor_id_2):
    raise NotImplementedError("Implement me!")

def actor_path(data, path):
    raise NotImplementedError("Implement me!")

def get_movie_path(data, actor_id_1, actor_id_2):
    raise NotImplementedError("Implement me!")

if __name__ == '__main__':
    # additional code here will be run only when lab.py is ran directly
    # (not when running test.py), so this is a good place to put code
    # to test anything
    with open("resources/IDToMovie.json", 'r') as f:
        IDToMovie = json.load(f)
    with open("resources/IDToName.json", 'r') as f:
        IDToName = json.load(f)
    
    filename = "resources/tiny.json"
    with open(filename) as f:
        data = json.load(f)
    