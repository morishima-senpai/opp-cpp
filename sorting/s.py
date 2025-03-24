def heapify(arr, i, n):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n:
        if arr[l] > arr[largest]:
            largest = l

    if r < n:
        if arr[r] > arr[largest]:
            largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, largest, n)
