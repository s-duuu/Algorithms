NORTH = 'North'
SOUTH = 'South'
EAST = 'East'
WEST = 'West'
STOP = 'Stop'

REVERSE = {NORTH: SOUTH,
               SOUTH: NORTH,
               EAST: WEST,
               WEST: EAST,
               STOP: STOP}

print(REVERSE.get(NORTH))