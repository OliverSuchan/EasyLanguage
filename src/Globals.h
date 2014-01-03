#ifndef GLOBALS_H
#define GLOBALS_H

/**
 * @brief Alle für das Programm benötigten enums
 */
namespace Global
{
    /**
     * @brief Enum für Verben<BR>
     * Zur Unterscheidung zwischen regelmäßigen und unregelmäßigen Verben @see Verb
     */
    enum VerbType
    {
        IRREGULAR,
        REGULAR
    };

    /**
     * @brief Enum für Vokabeln<BR>
     * Zeigt ob es sich bei der aktuellen Voc-Instanz um ein Wort oder Verb handelt @see Voc
     */
    enum VocType
    {
        WORD,
        VERB
    };

    /**
     * @brief Enum für die verschiedenen Lernstadien der aktuellen Vokabel @see Voc
     */
    enum LearningState
    {
        PERFECT,
        GOOD,
        OK,
        BAD
    };
}

#endif // GLOBALS_H
