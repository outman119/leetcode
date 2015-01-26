if (head == NULL)
        {
            return head;
        }
        ListNode big(x + 1), small(x - 1);
        auto bigger = &big;
        auto smaller = &small;
        auto header1 = smaller;
        auto header2 = bigger;
        while (head != NULL)
        {
            auto node = head->next;
            if (head->val < x)
            {
                smaller->next = head;
                head->next = NULL;
                smaller = head;
            }
            else
            {
                bigger->next = head;
                head->next = NULL;
                bigger = head;
            }
            head = node;
        }
        if (smaller == header1)
        {
            return header2->next;
        }
        else
        {
            smaller->next = header2->next;
            return header1->next;
        }
