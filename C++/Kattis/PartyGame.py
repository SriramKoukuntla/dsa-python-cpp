#start  = 2:40
#End: 4:08
def returnWatchingGuest(guests):
    for guest in guests:
        return guest

T = int(input())
for test in range(T):
    n = int(input())
    cards = list(map(int, input().split()))
    guests = {}
    for i in range(len(cards)): guests[i+1] = cards[i]

    valueRemoved = True
    watchingGuest = -1
    seen = -1
    while (len(guests) != 0):
        if (valueRemoved):
            watchingGuest = returnWatchingGuest(guests)
            seen = set()
            valueRemoved = False
        if (guests[watchingGuest] in seen): 
            print("Some starve.")
            break
        seen.add(guests[watchingGuest])
        guests2 = {}
        for guest, card in guests.items(): 
            guests2[guest] = guests[card]
            if (guests2[guest] == guest): 
                guests2.pop(guest)
                valueRemoved = True 
        guests = guests2
        if (len(guests) == 0): 
            print("All can eat.")
            break