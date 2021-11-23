/*  a. p = &i --> LEGAL
    b. *q = &j --> LEGAL
    c. p = &*&i --> LEGAL
    d. i = (*&)j --> ILEGAL
    e. i = *&j --> LEGAL
    f. i = &&j --> ILEGAL
    g. q = *p --> LEGAL
    h. i = (*p) + *q --> LEGAL */