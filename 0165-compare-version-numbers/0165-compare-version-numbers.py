class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        #parse string by . in python / C++
        v1 = version1.split('.')
        v2 = version2.split('.')
        n1, n2 = len(v1),len(v2)
        while n1 < n2:
            v1.append(0)
            n1 += 1
        while n2 < n1:
            v2.append(0)
            n2 += 1

        for i in range (max(n1,n2)):
            if int(v1[i]) > int(v2[i]):
                return 1
            if int(v2[i]) > int(v1[i]):
                return -1

        return 0
       
