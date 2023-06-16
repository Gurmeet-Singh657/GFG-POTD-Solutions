long long f(int ind, int lastCoordinate, vector<vector<long long>> &curr, vector<vector<long long>> &dp)
{
    if (ind == curr.size())
    {
        return abs(curr[ind - 1][lastCoordinate]);
    }

    if (dp[ind][lastCoordinate] != -1)
        return dp[ind][lastCoordinate];

    int prevlocn = curr[ind - 1][lastCoordinate];
    long long goleft = 1e18, goright = 1e18;
    // Case 1: if prevlocn>=onecoordinate and prevlocn<=secondCoordinate
    if (prevlocn >= curr[ind][0] && prevlocn <= curr[ind][1])
    {
        // Try to go left and then right
        long long dis1 = prevlocn - curr[ind][0] + curr[ind][1] - curr[ind][0];
        goleft = dis1 + f(ind + 1, 1, curr, dp);
        // Try to go Right and then left
        long long dis2 = curr[ind][1] - prevlocn + curr[ind][1] - curr[ind][0];
        goright = dis2 + f(ind + 1, 0, curr, dp);
    }
    // Case 2: first < second < prevlocn
    else if (curr[ind][0] <= curr[ind][1] && curr[ind][1] <= prevlocn)
    {
        // simple is to go left only from prevlocn
        long long dis1 = prevlocn - curr[ind][0];
        goleft = dis1 + f(ind + 1, 0, curr, dp);
    }
    // Case 3: prevlocn < first < second
    else
    {
        // simple is to go right only from prevlocn
        long long dis2 = curr[ind][1] - prevlocn;
        goright = dis2 + f(ind + 1, 1, curr, dp);
    }
    return dp[ind][lastCoordinate] = min(goleft, goright);
}
long long minTime(int n, vector<int> &locations, vector<int> &types)
{
    vector<pair<int, int>> vec(100001, {INT_MAX, INT_MIN});
    vec[0].first = 0, vec[0].second = 0; // for making first comparison
    for (int i = 0; i < n; i++)
    {
        int loc = locations[i];
        int type = types[i];
        vec[type].first = min(vec[type].first, loc);
        vec[type].second = max(vec[type].second, loc);
    }
    vector<vector<long long>> curr;
    for (int i = 0; i < 100001; i++)
    {
        if (vec[i].first == INT_MAX)
            continue;
        curr.push_back({vec[i].first, vec[i].second});
    }
    int m = curr.size();
    vector<vector<long long>> dp(m + 1, vector<long long>(2, -1));
    return f(1, 0, curr, dp);
}