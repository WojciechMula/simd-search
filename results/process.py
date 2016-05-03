import sys

def load_iters(file):
    iters = {}
    for line in file:
        if 'demo' in line:
            tmp = line.split()
            size  = int(tmp[1])
            count = int(tmp[2])

            iters[size] = count

    return iters


def load_data(file, iters):
    
    result = {}

    for line in file:
        F = line.split()
        try:
            size = int(F[0])
        except ValueError:
            continue

        # queries/second
        def normalize(s):
            time = float(s)
            
            return iters[size]/time

        result[size] = map(normalize, F[1:])

    return result


def main():
    try:
        results = sys.argv[1]
        script  = sys.argv[2]
    except IndexError:
        print "Usage: script results-file.txt experiment.sh"
        return

    with open(script) as f:
        iters = load_iters(f)

    with open(results) as f:
        r = load_data(f, iters)

    for key in sorted(r.keys()):
        print '%4d %s' % (key, ' '.join('%15.0f' % q for q in r[key]))


if __name__ == '__main__':
    main()
