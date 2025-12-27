// Copyright 2024 Fuzz Introspector Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Initialize charts when DOM is loaded
document.addEventListener('DOMContentLoaded', function() {
    initializeCharts();
});

function initializeCharts() {
    // Before Chart - showing poor coverage
    const beforeCtx = document.getElementById('beforeChart');
    if (beforeCtx) {
        new Chart(beforeCtx, {
            type: 'doughnut',
            data: {
                labels: ['Covered', 'Uncovered'],
                datasets: [{
                    data: [47.3, 52.7],
                    backgroundColor: ['#ef4444', '#e5e7eb'],
                    borderWidth: 0
                }]
            },
            options: {
                responsive: true,
                maintainAspectRatio: true,
                plugins: {
                    legend: {
                        position: 'bottom',
                    },
                    title: {
                        display: true,
                        text: 'Code Coverage Distribution'
                    }
                }
            }
        });
    }
    
    // After Chart - showing excellent coverage
    const afterCtx = document.getElementById('afterChart');
    if (afterCtx) {
        new Chart(afterCtx, {
            type: 'doughnut',
            data: {
                labels: ['Covered', 'Uncovered'],
                datasets: [{
                    data: [91.2, 8.8],
                    backgroundColor: ['#10b981', '#e5e7eb'],
                    borderWidth: 0
                }]
            },
            options: {
                responsive: true,
                maintainAspectRatio: true,
                plugins: {
                    legend: {
                        position: 'bottom',
                    },
                    title: {
                        display: true,
                        text: 'Code Coverage Distribution'
                    }
                }
            }
        });
    }
}

// Smooth scroll for anchor links
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        const target = document.querySelector(this.getAttribute('href'));
        if (target) {
            target.scrollIntoView({
                behavior: 'smooth',
                block: 'start'
            });
        }
    });
});

// Add scroll-based animations
window.addEventListener('scroll', function() {
    const scrolled = window.pageYOffset;
    const parallax = document.querySelector('.gradient-bg');
    if (parallax) {
        parallax.style.transform = `translateY(${scrolled * 0.5}px)`;
    }
});
