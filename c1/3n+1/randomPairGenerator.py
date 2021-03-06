# writes a list of randomly generated pairs to a file
# can specify min, max values, and number of pairs to generate

import argparse, os, random

def generate_pairs(min, max, num_pairs):
    pairs = list()
    for i in range(0, num_pairs):
        i = random.randint(min, max) 
        j = random.randint(min, max)
        pair = (i, j) if i < j else (j, i)
        pairs.append(pair)

    # write to file
    size = 'small' if num_pairs < 250 else 'big'
    filename = "input/" + size + "_n" + str(num_pairs) + "_min" + str(min) + "_max" + str(max) + ".txt"
    print("written to %s" % filename)
    with open(filename, 'w') as f:
        f.write("num pairs: %d, min val: %d, max val: %d\n" % (num_pairs, min, max))
        for (i, j) in pairs:
            f.write("%d %d\n" % (i, j))

def main(args):
    generate_pairs(args.min, args.max, args.num)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Generate random pairs (i, j) such that i < j')
    parser.add_argument('-m', '--min', type=int, required=True, help='min val')
    parser.add_argument('-x', '--max', type=int, required=True, help='max val')
    parser.add_argument('-n', '--num', type=int, required=True, help='num pairs to generate')
    args = parser.parse_args()
    main(args)
