[TOC]

# ray

@import "./ray.png"

Given some ray with the origin (starting point) $o_r \in \R^3$ and the direction $d_r \in \R^3$,
the ray at time $t$ can be represented as follows.
$ray\_at(t) = o_r + td_r$

---

# sphere

@import "./sphere.png"

Given some sphere with the center $c_{sp} \in \R^3$ and the radius $r_{sp}\in\R$,

the point $p \in \R^3$ is on this sphere
$\Leftrightarrow |p - c_{sp}| = r_{sp}$

## sphere_get_dist

Given some ray and sphere, there can be the time $t$ which $ray\_at(t)$ is on the sphere. Such $t$ can be calculated as follows.
$|ray\_at(t) - c_{sp}| = r_{sp}$
$\Leftrightarrow |o_r + td_r - c_{sp}| = r_{sp}$
$\Leftrightarrow |td_r + o_r - c_{sp}| = r_{sp}$ $\Leftrightarrow (td_r + o_r - c_{sp})\cdot(td_r + o_r - c_{sp}) = r_{sp}^2$
$\Leftrightarrow |d_r|^2t^2 + 2(d_r\cdot(o_r - c_{sp}))t + |o_r - c_{sp}|^2 - r_{sp}^2 = 0$

if $|d_r| = 1$ with $B \coloneqq d_r\cdot(o_r-c_{sp}),\ C \coloneqq |o_r - c_{sp}|^2 - r_{sp}^2$
$\Rightarrow t^2 + 2Bt + C = 0$

Solving this quadratic equation with checking those $t$ satisfy $t > 0$,
we know not only whether the ray hits the sphere or not, but also the time (distance) it hits the sphere as well.

## sphere_get_normal

Given the point $p$ on some sphere, one way to get the normal vector $n$ (representing the local tangent space on this $p$) is to just subtract the center of the sphere.

$n = p - c_{sp}$

But for the ray hitting the point $p$ from the inside of this sphere, one may needs its opposite vector.

---

# plane

@import "./plane.png"

Given some plane with the origin (just one point on this plane) $o_p \in \R^3$ and the normal vector $n_p \in \R^3$,

the point $p \in \R^3$ is on this plane
$\Leftrightarrow (p - o_p)\cdot n_p = 0$

## plane_get_dist

Given some ray and plane, there can be the time $t$ which $ray\_at(t)$ is on the plane. Such $t$ can be calculated as follows.

$(ray\_at(t) - o_p) \cdot n_p = 0$
$\Leftrightarrow (o_r + td_r - o_p) \cdot n_p = 0$
$\Leftrightarrow (d_r\cdot n_p)t = - (o_r - o_p) \cdot n_p$

if $ d_r\cdot n_p \neq 0$, 
$\Rightarrow t = - \frac{(o_r - o_p) \cdot n_p}{d_r\cdot n_p}$

if $ d_r\cdot n_p = 0$,
$\quad$ either the $ray\_at(t)$ is on the plane for any $t \geq 0$,
$\quad$ or the $ray\_at(t)$ is not on the plane for any $t \geq 0 $.

## plane_get_normal

For the plane, the normal vector $n$ of some hit point $p$ on the plane, is just the normal vector of the plane itself.

$n = n_p$

As same for the sphere case, the normal vector needs be the opposite depending on the direction of the incoming ray.

---

# cylinder

@import "./cylinder.png"

Given some cylinder with the center $c_c \in \R^3$, the direction $d_c \in \R^3$, the radius $r_c \in \R$, and the height (from center to top) $h_c \in \R$,

the point $p \in \R^3$ is on this cylinder
$\Leftrightarrow$
$\qquad
  \left\{
    \begin{array}{l}
			|projected(p - c_c, d_c)| = r_c \\
			\\
			|(p - c_c)\cdot d_c | < h_c
    \end{array}
  \right.
$

where
$\qquad projected(u, n) = u - (u\cdot n)n$
@import "./projected.png"

## cylinder_get_dist

Given some ray and cylinder, there can be the time $t$ which $ray\_at(t)$ is on the cylinder. Such $t$ can be calculated as follows.

$\qquad
  \left\{
    \begin{array}{l}
			|projected(ray\_at(t) - c_c, d_c)| = r_c \\
			\\
			|(ray\_at(t) - c_c)\cdot d_c | < h_c
    \end{array}
  \right.
$

$\Leftrightarrow\quad
  \left\{
    \begin{array}{l}
			|projected(td_r + o_r - c_c, d_c)| = r_c \\
			\\
			|(td_r + o_r - c_c)\cdot d_c | < h_c
    \end{array}
  \right.
$

$\Leftrightarrow\quad
  \left\{
    \begin{array}{l}
			|projected(td_r + oc, d_c)| = r_c \\
			\\
			|(td_r + oc)\cdot d_c | < h_c
    \end{array}
  \right.
$ where $ oc = o_r - c_c$

$\Leftrightarrow\quad
  \left\{
    \begin{array}{l}
			|t\ projected(d_r,d_c) + projected(oc, d_c)| = r_c \\
			\\
			|(td_r + oc)\cdot d_c | < h_c
    \end{array}
  \right.
$

Comparing the first quadratic equation to the 'sphere_get_dist' case, we can get roots $(t \in \R)$ of the equation.
And at the same time those $t$ must satisfy the second equation with $t \geq 0$.

## cylinder_get_normal

Given the hit point $p$ on the cylinder, the normal vector $n$ is nothing but the projected direction from the center of the cylinder to the hit point $p$.

$n = projected(p - d_c, d_c)$

As spheres and planes, it should be the opposite one depending the ray hits the interior part of the cylinder. And, for example, this can be checked using the following condition.

Any normal vector of the hit point should be roughly the opposite direction of the incoming ray.
$\Rightarrow n \cdot d_r < 0$
