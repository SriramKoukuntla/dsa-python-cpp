#https://leetcode.com/problems/course-schedule/
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjMat = {i: [] for i in range(numCourses)}
        for course, prereq in prerequisites:
            adjMat[course].append(prereq)

        for course in range(numCourses):
            stack = [(course, set())]
            while stack:
                curCourse, visited = stack.pop()
                if curCourse in visited:
                    return False
                visited.add(curCourse)
                for pre in adjMat[curCourse]:
                    stack.append((pre, visited.copy()))
            adjMat[course] = []
        return True
    
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjMat = {i: set() for i in range(numCourses)}
        for course, prereq in prerequisites:
            adjMat[course].add(prereq)

        def delete(course):
            for i in range(numCourses):
                if course in adjMat[i]:
                    adjMat[i].remove(course)
                    if len(adjMat[i]) == 0:
                        delete(i)

        for course in range(numCourses):
            if len(adjMat[course]) == 0:
                delete(course)
        
        for course in range(numCourses):
            if len(adjMat[course]) != 0:
                return False
        return True