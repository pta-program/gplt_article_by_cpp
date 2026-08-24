#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-004 肿瘤诊断
 *
 * 题目描述：
 *   在医学影像中，病灶区域由三维空间中相连的 voxels（体素）构成。
 *   给定一个三维体素数组，其中 1 表示病灶体素，0 表示正常体素。
 *   如果一个病灶连通块的大小（体素数量）不小于给定的阈值，则认为是一个肿瘤。
 *   求所有肿瘤包含的体素总数。
 *   输入格式：第一行给出四个整数 M、N、L、T，分别表示三维数组的长、宽、高和阈值。
 *   接下来 L 层，每层 M 行，每行 N 个 0 或 1。
 *   输出格式：输出所有肿瘤包含的体素总数。
 *
 * 实现原理：
 *   使用广度优先搜索（BFS）遍历三维空间，统计每个连通块的大小。
 *   1. 将三维数组展平为一维数组 voxel[]，便于索引。
 *   2. 使用队列 queue[] 进行 BFS。
 *   3. 六方向搜索：每个体素 (x,y,z) 有六个相邻体素：
 *      (x±1,y,z), (x,y±1,z), (x,y,z±1)。
 *   4. 遍历每个体素，如果是未访问的病灶体素（值为 1），则启动 BFS。
 *   5. BFS 过程中，将访问过的体素标记为 0（避免重复访问），统计连通块大小。
 *   6. 如果连通块大小 >= 阈值，则累加到答案中。
 *
 * 时间复杂度：O(M * N * L)，每个体素最多被访问一次
 */
int main(void) {
    int m, n, l, threshold, plane, total, i, value, answer = 0;
    unsigned char *voxel;
    int *queue;
    if (scanf("%d%d%d%d", &m, &n, &l, &threshold) != 4) return 0;
    plane = m * n; total = plane * l;
    voxel = (decltype(voxel))malloc((size_t)total); queue = (decltype(queue))malloc((size_t)total * sizeof(int));
    if (!voxel || !queue) { free(voxel); free(queue); return 0; }
    for (i = 0; i < total; ++i) { scanf("%d", &value); voxel[i] = (unsigned char)value; }
    for (i = 0; i < total; ++i) {
        int head = 0, tail = 0, count = 0;
        if (!voxel[i]) continue;
        queue[tail++] = i; voxel[i] = 0; /* 入队即标记，避免重复访问。 */
        while (head < tail) {
            int p = queue[head++], z = p / plane, rest = p % plane;
            int x = rest / n, y = rest % n, next;
            ++count;
            if (z > 0) { next = p - plane; if (voxel[next]) { voxel[next] = 0; queue[tail++] = next; } }
            if (z + 1 < l) { next = p + plane; if (voxel[next]) { voxel[next] = 0; queue[tail++] = next; } }
            if (x > 0) { next = p - n; if (voxel[next]) { voxel[next] = 0; queue[tail++] = next; } }
            if (x + 1 < m) { next = p + n; if (voxel[next]) { voxel[next] = 0; queue[tail++] = next; } }
            if (y > 0) { next = p - 1; if (voxel[next]) { voxel[next] = 0; queue[tail++] = next; } }
            if (y + 1 < n) { next = p + 1; if (voxel[next]) { voxel[next] = 0; queue[tail++] = next; } }
        }
        if (count >= threshold) answer += count;
    }
    printf("%d\n", answer); free(voxel); free(queue); return 0;
}
