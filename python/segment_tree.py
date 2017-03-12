def get_mid(start, end):
    return (end - start) / 2

def _build_tree(node, start, end, arr, tree):
    #print start,end
    if start == end:
        tree[node] = arr[start]
    else:
        mid = get_mid(start, end)
        _build_tree(node*2, start, mid, arr, tree)
        _build_tree((node*2)+1, mid+1, end, arr, tree)
        tree[node] = tree[node*2] + tree[(node*2)+1]

def _get_sum(node, start, end, l, r, tree):
    if l > end or r < start:
        return 0
    elif l <= start and r >= end:
        return tree[node]
    else:
        mid = get_mid(start, end)
        l_sum = _get_sum(node*2, start, mid, l, r, tree)
        r_sum = _get_sum((node*2)+1, mid+1, end, l, r, tree)
        return l_sum+r_sum

def _update(node, start, end, idx, val, tree):
    if start == end:
        tree[node] = val
    else:
        mid = get_mid(start, end)
        if idx <= mid:
            _update(node*2, stat, mid, idx, val, tree)
        else:
            _update((node*2)+1, mid+1, end, idx, val, tree)
        tree[node] = tree[node*2] + tree[(node*2)+1]

def build_tree(arr, tree):
    _build_tree(1, 0, len(arr)-1, arr, tree)

def get_sum(l, r, tree):
    return _get_sum(1, 0, len(tree)/2 - 1, l, r, tree)

def update(idx, val, tree):
    _update(1, 0, len(tree)/2 - 1, idx, val, tree)

arr = [1, 2, 3]
tree = [0]*(2*len(arr))

build_tree(arr,tree)

print get_sum(1,2,tree)