def get_length(dna):
    """ (str) -> int

    Return the length of the DNA sequence dna.

    >>> get_length('ATCGAT')
    6
    >>> get_length('ATCG')
    4
    """
    return len(dna)


def is_longer(dna1, dna2):
    """ (str, str) -> bool

    Return True if and only if DNA sequence dna1 is longer than DNA sequence
    dna2.

    >>> is_longer('ATCG', 'AT')
    True
    >>> is_longer('ATCG', 'ATCGGA')
    False
    """
    if len(dna1)>len(dna2):
        return True
    else:
        return False

    

def count_nucleotides(dna, nucleotide):
    """ (str, str) -> int

    Return the number of occurrences of nucleotide in the DNA sequence dna.

    >>> count_nucleotides('ATCGGC', 'G')
    2
    >>> count_nucleotides('ATCTA', 'G')
    0
    """
    count = 0
    for char in dna:
        if char == nucleotide:
            count = count + 1
            
    return count


def contains_sequence(dna1, dna2):
    """ (str, str) -> bool

    Return True if and only if DNA sequence dna2 occurs in the DNA sequence
    dna1.

    >>> contains_sequence('ATCGGC', 'GG')
    True
    >>> contains_sequence('ATCGGC', 'GT')
    False

    """
    if dna1.find(dna2)>=0:
        return True
    else:
        return False

def is_valid_sequence(dna):
    ''' (str) -> bool

    Return True if and only if the nuclotide is a valid sequence that contains only
    A, C, T or G.
    
    >>> is_valid_sequence('ACTG')
    True
    
    >>> is_valid_sequence('AdTG')
    False
    '''
    valid = 'ATCG'
    count = 0
    r = True

    for char in dna:
        if char not in 'ATCG':
            return False
    return r
        
    
def insert_sequence(dna1, dna2, index):
    ''' (str, str, int) -> str

    Return the new dna sequqnce with the second dna sequqnce added to the index of
    the first one.

    >>> insert_sequence('CCGG', 'AT', 2) ->
    'CCATGG'
    '''
    new = dna1[0:index] + dna2 + dna1[index:]
    return new

def get_complement(dna):
    ''' (str) -> (str)

    Return the complelemnt of the DNA string provided.

    >>> get_complement('ATCG')
    'TAGC'

    >>> get_complement('AAAA')
    'TTTT'
    '''

    new_string = ''
    for char in dna:
        if char == 'A':
            new_string = new_string + 'T'
        elif char == 'T':
            new_string = new_string + 'A'
        elif char == 'C':
            new_string = new_string + 'G'
        else:
            new_string = new_string + 'C'
            
    return new_string

def get_complementary_sequence(dna):
    ''' (str) -> (str)

    Reverses the string.

    >>> get_complementary_sequence('AT')
    TA
    '''
    new_string = ''
    for char in dna:
        new_string = new_string + get_complement(char)
    return new_string

def mystery(s):
    i = 0
    result = ''

    while not s[i].isdigit():
          result = result + s[i]
          i = i + 1

    return result


def increment_items(L, increment):
    i = 0
    while i < len(L):
        L[i] = L[i] + increment
        i = i + 1
