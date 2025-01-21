polyptr addpoly(polyptr a, polyptr b) {
    polyptr c, *temp;
    
    // Allocate memory for the resulting polynomial
    c = (struct poly *)malloc(sizeof(struct poly));
    temp = &c;
    
    while (a->link && b->link) {
        if (a->exp > b->exp) {
            c->exp = a->exp;
            c->coef = a->coef;
            a = a->link;
        } else if (a->exp < b->exp) {
            c->exp = b->exp;
            c->coef = b->coef;
            b = b->link;
        } else {
            c->exp = a->exp;
            c->coef = a->coef + b->coef;
            a = a->link;
            b = b->link;
        }
        
        // Allocate memory for the next node
        c->link = (struct poly *)malloc(sizeof(struct poly));
        c = c->link;
        c->link = NULL;
    }
    
    // Add remaining terms from either polynomial
    while (a->link || b->link) {
        if (a->link) {
            c->exp = a->exp;
            c->coef = a->coef;
            a = a->link;
        }
        if (b->link) {
            c->exp = b->exp;
            c->coef = b->coef;
            b = b->link;
        }
        
        // Allocate memory for the next node
        c->link = (struct poly *)malloc(sizeof(struct poly));
        c = c->link;
        c->link = NULL;
    }

    return temp;
}
