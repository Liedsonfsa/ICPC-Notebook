inline int solve(vi& v, int l, int r) {
    int ans = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        ans += solve(v, l, mid);
        ans += solve(v, mid+1, r);

        int i, j = mid + 1, k;
        i = k = l;
      
        while((i <= mid) and (j <= r)) {
            aux[k++] = min(v[i], v[j]);
            if (aux[k - 1] == v[j]) {
                ++j;
                ans += (mid - i + 1);
            } else ++i;
        }
        while (i <= mid) aux[k++] = v[i++];
        while (j <= r) aux[k++] = v[j++];
        for (i = l; i <= r;i++) v[i] = aux[i];
    }
    return ans;
}
