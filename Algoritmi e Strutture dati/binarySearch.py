
def binary_recursive(vet,low,high,target):
    if high>=low:
        mid = low+(high-low)//2  #floor
        if vet[mid]==target:
            return True
        elif target>vet[mid]: return binary_recursive(vet,mid+1,high,target)
        else: return binary_recursive(vet,low,mid-1,target)
    else:
        return False

def binary_iterative(vet,low,high,target):
    while high>=low:
        mid = low+(high-low)//2
        if vet[mid]==target:
            return True
        elif target>vet[mid]: low=mid+1
        else: high=mid-1
    return False

vet = [1,2,3,4,5,6,7,8,9]
print(binary_iterative(vet,0,len(vet)-1,3))