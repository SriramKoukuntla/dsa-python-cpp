#https://leetcode.com/problems/course-schedule-ii/description/
from collections import deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        prereqs = {i:[] for i in range(numCourses)}
        for course, preReqs in prerequisites:
            prereqs[course].append(preReqs)
        cycle = set()
        visited = set()
        ret = []
        def helper(node):
            if node in visited:
                return True
            if node in cycle:
                return False
            cycle.add(node)
            for child in prereqs[node]:
                if not helper(child):
                    return False
            visited.add(node)
            ret.append(node)
            cycle.remove(node)
            prereqs[node] = []
            return True

        for course in range(numCourses):
            if not helper(course):
                return []
        return ret