vector<vector<int>> matrix(m, vector<int>(n, -1));

        // Boundaries for the spiral traversal
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        ListNode* current = head;

        // Continue filling the matrix in a spiral order until we run out of the linked list
        while (top <= bottom && left <= right && current != nullptr) {
            // Move from left to right
            for (int i = left; i <= right && current != nullptr; ++i) {
                matrix[top][i] = current->val;
                current = current->next;
            }
            top++;

            // Move from top to bottom
            for (int i = top; i <= bottom && current != nullptr; ++i) {
                matrix[i][right] = current->val;
                current = current->next;
            }
            right--;

            // Move from right to left
            for (int i = right; i >= left && current != nullptr; --i) {
                matrix[bottom][i] = current->val;
                current = current->next;
            }
            bottom--;

            // Move from bottom to top
            for (int i = bottom; i >= top && current != nullptr; --i) {
                matrix[i][left] = current->val;
                current = current->next;
            }
            left++;
        }

        return matrix;
