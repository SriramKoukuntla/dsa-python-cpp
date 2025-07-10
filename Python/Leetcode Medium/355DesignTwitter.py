from collections import defaultdict, deque
class Twitter:

    def __init__(self):
        self.time = 0
        self.following = defaultdict(set) #key = userId, value = set() of users they follow
        self.posts = defaultdict(deque) #key = userId, value = queue of posts and their time

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.following[userId].add(userId)
        self.posts[userId].append((self.time, tweetId))
        if len(self.posts[userId]) > 10:
            self.posts[userId].popleft()
        self.time-=1

    def getNewsFeed(self, userId: int) -> List[int]:
        allPosts = []
        for influencer in self.following[userId]:
            allPosts += self.posts[influencer]
        heapq.heapify(allPosts)
        ret = []
        length = min(10, len(allPosts))
        for i in range(length):
            ret.append(heapq.heappop(allPosts)[1])
        return ret

    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.following[followerId]:
            self.following[followerId].remove(followeeId)

# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)